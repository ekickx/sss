void // lalala 
drawroundedcorners(Client *c) {
    // Directly stolen from Mitch Weaver's dwm
    // https://github.com/MitchWeaver/dotfiles/blob/8d76e479715e7fa7b4df153719d3d25144f9f7f2/suckless-tools/dwm/dwm/dwm.c#L938
    if(round_radius > 0 && c) {
        Window win;
        win = c->win;
        if(!win) return;
        XWindowAttributes win_attr;
        
        if(!XGetWindowAttributes(dpy, win, &win_attr)) return;

        const int w = c->w;
        const int h = c->h;

        const int dia = 2 * round_radius; // set in config.h
        if(w < dia || h < dia) return;

        Pixmap mask;
        mask = XCreatePixmap(dpy, win, w, h, 1);
        if(!mask) return;

        XGCValues xgcv;
        GC shape_gc;
        shape_gc = XCreateGC(dpy, mask, 0, &xgcv);

        if(!shape_gc) {
            XFreePixmap(dpy, mask);
            free(shape_gc);
            return;
        }

        XSetForeground(dpy, shape_gc, 0);
        XFillRectangle(dpy, mask, shape_gc, 0, 0, w, h);
        XSetForeground(dpy, shape_gc, 1);
        XFillArc(dpy, mask, shape_gc, 0, 0, dia, dia, 0, 23040);
        XFillArc(dpy, mask, shape_gc, w-dia-1, 0, dia, dia, 0, 23040);
        XFillArc(dpy, mask, shape_gc, 0, h-dia-1, dia, dia, 0, 23040);
        XFillArc(dpy, mask, shape_gc, w-dia-1, h-dia-1, dia, dia, 0, 23040);
        XFillRectangle(dpy, mask, shape_gc, round_radius, 0, w-dia, h);
        XFillRectangle(dpy, mask, shape_gc, 0, round_radius, w, h-dia);
        XShapeCombineMask(dpy, win, ShapeBounding, 0, 0, mask, ShapeSet);
        XFreePixmap(dpy, mask);
        XFreeGC(dpy, shape_gc);
    }
}
