struct ANSI {
  static constexpr char reset[] = "\033[0m";

  static constexpr char red[] = "\033[31m";
  static constexpr char green[] = "\033[32m";
  static constexpr char yellow[] = "\033[33m";
  static constexpr char blue[] = "\033[34m";
  static constexpr char magenta[] = "\033[35m";
  static constexpr char cyan[] = "\033[36m";
  static constexpr char white[] = "\033[37m";

  static constexpr char bgRed[] = "\033[41m";
  static constexpr char bgGreen[] = "\033[42m";
  static constexpr char bgYellow[] = "\033[43m";
  static constexpr char bgBlue[] = "\033[44m";
  static constexpr char bgMagenta[] = "\033[45m";
  static constexpr char bgCyan[] = "\033[46m";
  static constexpr char bgWhite[] = "\033[47m";

  static constexpr char italic[] = "\033[3m";
  static constexpr char underline[] = "\033[4m";
  static constexpr char bold[] = "\033[1m";
};