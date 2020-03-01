#include "main.h"
#include "console/command.h"

CONSOLE_COMMAND(move_motor)
{
  if (argc != 3) {
    printf("Invalid number of arguments: %d\n", argc);
    printf("move_motor 1 127");
  }

  motor_move(argv[1].i, argv[2].i);

  return 0;
}

STATIC_COMMAND_START_NAMED(pros_builtins)
STATIC_COMMAND("motor_move", "Sets the voltage for the motor from -127 to 127.", move_motor)
STATIC_COMMAND_END_NAMED(pros_builtins);
