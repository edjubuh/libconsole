/*
 * Copyright (c) 2020 Elliot Berman
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT
 */

#include "console/console.h"

extern cmd_block __commands_start;
extern cmd_block __commands_end;

__attribute__((constructor(200))) static void console_install_hot_cmds(void) {
  cmd_block *block;
  for (block = &__commands_start; block != &__commands_end; block++) {
    console_register_commands(block);
  }
}
