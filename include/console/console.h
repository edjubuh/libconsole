/*
 * Copyright (c) 2008-2009 Travis Geiselbrecht, 2020 Elliot Berman
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT
 */
#pragma once


/* Previously, this file was included to get access to defining a console
 * command. This logic has been moved into the following header, which is
 * what in almost every case what regular code wants to include instead of
 * this file.
 */
#include "console/command.h"

#ifdef __cplusplus
extern "C" {
#endif
/* external api */
/**
 * console_start_task: initialize and start console
 */
void console_start_task(void);

/**
 * console_register_commands: Register an array of command blocks
 *
 * libconsole registers all statically defined commands in the .commands
 * section (e.g. using STATIC_COMMAND_START/END). This function could be
 * used for dynamically created commands.
 */
void console_register_commands(cmd_block *block);

/**
 * console_get_command_handler: Get the callback for a command
 */
console_cmd console_get_command_handler(const char *command);

/**
 * console_run_script: Inject input into the console
 */
int console_run_script(const char *string);

/**
 * console_abort_script: Abort the currently running console_run_script
 */
void console_abort_script(void);

extern int lastresult;

#ifdef __cplusplus
}
#endif
