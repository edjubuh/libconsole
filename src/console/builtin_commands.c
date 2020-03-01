#include "main.h"
#include "console/command.h"

/**
 * This macro expands into a function prototype, e.g.
 * static int move_motor(int argc, const cmd_args *argv)
 */
CONSOLE_COMMAND(move_motor)
{
  if (argc != 3) {
    printf("Invalid number of arguments: %d\n", argc);
    printf("move_motor 1 127");
  }

  /**
   * argv[0] is command name (move_motor)
   * argv[1] is first argument
   * argv[2] is second argument, and so on
   * First argument is motor port, second argument is desired speed
   * Note: if first or second arguments aren't integers, then "argv[x].i" is 0
   *       If you don't trust the user, then you'll need to do sscanf yourself
   *       to convert argv[x].str to whatever format
   */
  motor_move(argv[1].i, argv[2].i);

  return 0;
}
/**
 * This macro registers the command with console
 * First parameter is function name
 * Second parameter is optional and is help text when running "help" command
 * Third parameter is optional and is command string to use. Function name is default if not provided
 */
STATIC_COMMAND_SINGLE(move_motor);
