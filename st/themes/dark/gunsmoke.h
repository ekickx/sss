const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#1e2530", /* black   */
  [1] = "#618B95", /* red     */
  [2] = "#8E9391", /* green   */
  [3] = "#A0A29A", /* yellow  */
  [4] = "#ACB3A7", /* blue    */
  [5] = "#DBAC96", /* magenta */
  [6] = "#BBC3B5", /* cyan    */
  [7] = "#eadecf", /* white   */

  /* 8 bright colors */
  [8]  = "#a39b90",  /* black   */
  [9]  = "#618B95",  /* red     */
  [10] = "#8E9391", /* green   */
  [11] = "#A0A29A", /* yellow  */
  [12] = "#ACB3A7", /* blue    */
  [13] = "#DBAC96", /* magenta */
  [14] = "#BBC3B5", /* cyan    */
  [15] = "#eadecf", /* white   */

  /* special colors */
  [256] = "#1e2530", /* background */
  [257] = "#eadecf", /* foreground */
  [258] = "#eadecf",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 7;
 unsigned int defaultcs = 7;
 unsigned int defaultrcs= 7;
