const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#0D0F14", /* black   */
  [1] = "#3C5664", /* red     */
  [2] = "#4A4E55", /* green   */
  [3] = "#5E6167", /* yellow  */
  [4] = "#997267", /* blue    */
  [5] = "#C18D74", /* magenta */
  [6] = "#738793", /* cyan    */
  [7] = "#decfc6", /* white   */

  /* 8 bright colors */
  [8]  = "#9b908a",  /* black   */
  [9]  = "#3C5664",  /* red     */
  [10] = "#4A4E55", /* green   */
  [11] = "#5E6167", /* yellow  */
  [12] = "#997267", /* blue    */
  [13] = "#C18D74", /* magenta */
  [14] = "#738793", /* cyan    */
  [15] = "#decfc6", /* white   */

  /* special colors */
  [256] = "#0D0F14", /* background */
  [257] = "#decfc6", /* foreground */
  [258] = "#decfc6",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 7;
 unsigned int defaultcs = 7;
 unsigned int defaultrcs= 7;
