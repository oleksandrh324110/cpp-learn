struct ANSI {
  static const constexpr char *reset = "\033[0m";

  static const constexpr char *gray = "\033[30m";
  static const constexpr char *red = "\033[31m";
  static const constexpr char *green = "\033[32m";
  static const constexpr char *yellow = "\033[33m";
  static const constexpr char *blue = "\033[34m";
  static const constexpr char *magenta = "\033[35m";
  static const constexpr char *cyan = "\033[36m";
  static const constexpr char *white = "\033[37m";

  static const constexpr char *bgRed = "\033[41m";
  static const constexpr char *bgGreen = "\033[42m";
  static const constexpr char *bgYellow = "\033[43m";
  static const constexpr char *bgBlue = "\033[44m";
  static const constexpr char *bgMagenta = "\033[45m";
  static const constexpr char *bgCyan = "\033[46m";
  static const constexpr char *bgWhite = "\033[47m";

  static const constexpr char *italic = "\033[3m";
  static const constexpr char *underline = "\033[4m";
  static const constexpr char *bold = "\033[1m";
};