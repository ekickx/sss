static const char norm_fg[] = "#decfc6";
static const char norm_bg[] = "#0D0F14";
static const char norm_border[] = "#9b908a";

static const char sel_fg[] = "#decfc6";
static const char sel_bg[] = "#4A4E55";
static const char sel_border[] = "#decfc6";

static const char urg_fg[] = "#decfc6";
static const char urg_bg[] = "#3C5664";
static const char urg_border[] = "#3C5664";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeUrg] =  { urg_fg,      urg_bg,    urg_border },
};
