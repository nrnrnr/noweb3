static int xglobmatch (char *string, char *exp) {
    char *sp, *ep;              /* point into string and exp */
    char *starpos;              /* position in string when Star found */

    for (sp=string, ep=exp; ; sp++, ep++)
        switch (*ep) {
            case '*':   starpos = sp;
                        while (*sp) sp++;               /* point to trailing 0 */
                        for(; sp >= starpos; sp--) 
                            if (xglobmatch(sp,ep+1))
                                return 1;
                        return 0;
            case '?':   if (!*sp) return 0;
                        break;
            case '\\':  ep++; /* fall through */
            case '[':   { char c = *sp;
                          char matched = 0;
                          ep++;
                          if (!c) return 0;             /* end of string can't match any class */
                          do {
                            if (*ep && ep[1] == '-' && ep[2]) {
                              matched |= (ep[0] <= c && c <= ep[2]);
                              ep += 3;
                            } else if (*ep) {
                              matched |= *ep == c;
                              ep++;
                            }
                          } while (*ep && *ep != ']');
                          if (*ep != ']' || !matched) return 0;
                        }; break;
            default:    if (*sp != *ep) return 0;
                        if (*sp == 0) return 1;
                        break;
        }
    return 0;
}


int globmatch (char *string, char *exp) {
  int n = xglobmatch(string, exp);
  /*   printf("%s %s pattern %s\n", string, n ? "matches" : "does not match", exp); */
  return n;
}

