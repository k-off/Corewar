/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/03 14:16:01 by lskrauci       #+#    #+#                */
/*   Updated: 2019/09/15 16:13:15 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "visual.h"
# include "op.h"

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define MAGIC_HEADER_LENGTH	(4)
# define CHAMPION_SIZE_ENCODE	(4)
# define NULL_BYTES				(8)
# define COREWAR_EXEC_MAGIC		0xea83f3
# define CYCLES_TO_DIE			1536
# define JUST_RETURN			2147483647

/*
** int		type
** type of the line
** 1: only instruction
** 2: only label
** 3: instuction + label
*/

/*
** arg_type
** T_REG 1
** T_DIR 2
** T_IND 3
** EMPTY -1
*/

/*
** CODAGE OCTAL
** 0 = only 1 arg
** 1 = more than 1
*/

typedef struct			s_ins
{
	int					type;
	char				*label;
	char				*command;
	int					opcode;
	int					codage;
	char				*arg1;
	int					arg1_type;
	int					arg1_size;
	char				*arg2;
	int					arg2_type;
	int					arg2_size;
	char				*arg3;
	int					arg3_type;
	int					arg3_size;
	int					total_size;
	int					fix_label;
	struct s_ins		*next;
}						t_instruction;

typedef struct			s_players
{
	int					id;
	char				*name;
	char				*comment;
	int					executable_size;
	unsigned char		*executable;
	int					auto_gen_id;
}						t_players;

typedef struct			s_carriage
{
	int					id;
	int					carry;
	int					current_position;
	unsigned int		current_opcode;
	int					cycle_live_reported;
	int					cycles_before_execution;
	int					jump;
	int					operation_performed;
	int					r1;
	int					r2;
	int					r3;
	int					r4;
	int					r5;
	int					r6;
	int					r7;
	int					r8;
	int					r9;
	int					r10;
	int					r11;
	int					r12;
	int					r13;
	int					r14;
	int					r15;
	int					r16;
}						t_carriage;

typedef struct			s_cw
{
	int					warrior_count;
	int					nflag;
	int					nflagcount;
	int					double_n;
	int					dumpflag;
	int					dumpcycle;
	int					custom_id;
	int					save_d;
	int					lflag;
}						t_cw;

typedef struct			s_types
{
	int					type1;
	int					type2;
	int					type3;
}						t_types;

typedef struct			s_hist
{
	int					frame_nr;
	unsigned char		*mem;
	int					*color_map;
	t_carriage			**cursors;
	struct s_hist		*prev;
	struct s_hist		*next;
}						t_hist;

void					handle_events(void);
void					draw_carriage_info(t_win *win,
						t_carriage *carriage, int crg_nr);
void					draw_carriage_info2(t_win *win,
						t_carriage *carriage, int color);
int						redraw_window(t_hist *display_frame);
t_hist					*get_current_frame(t_hist *frame, int flag);
int						line_length(char *buffer, int i);
void					skip_blank(char *buffer, int *i);
void					skip_blank_mini(char *buffer, int *i);
void					skip_blank_end(char *buffer, int *i);
char					*save_comment(char c);
char					*save_name(char c);
void					save_char(char c, int mode);
void					save_content(char *buffer, int *i, int mode);
void					get_mode(char *buffer, int *i, int *mode, int *doubles);
int						validate_header(char *buffer);
void					input(int fd, int size);
int						is_label(char *command);
int						is_label_command(char *command);
t_instruction			*validate_body(char *buffer, int i);
int						is_command(char *command);
t_instruction			*instruction_origin(char *command, int type);
void					instruction_append(t_instruction *i, char *c, int t);
void					instructions_list(t_instruction **i, char *c, int t);
int						is_label_char(char c);
int						is_t_dir(char *arg);
int						is_t_ind(char *arg);
int						is_reg(char *arg);
void					replace_comma_space(char *command);
int						master_validator(char *c, t_instruction *i);
int						live_valid(char *command, t_instruction *instruction);
int						ld_valid(char *command, t_instruction *instruction);
int						st_valid(char *command, t_instruction *instruction);
int						add_valid(char *command, t_instruction *instruction);
int						sub_valid(char *command, t_instruction *instruction);
int						and_valid(char *command, t_instruction *instruction);
int						or_valid(char *command, t_instruction *instruction);
int						xor_valid(char *command, t_instruction *instruction);
int						zjmp_valid(char *command, t_instruction *instruction);
int						ldi_valid(char *command, t_instruction *instruction);
int						sti_valid(char *command, t_instruction *instruction);
int						fork_valid(char *command, t_instruction *instruction);
int						lld_valid(char *command, t_instruction *instruction);
int						lldi_valid(char *command, t_instruction *instruction);
int						lfork_valid(char *command, t_instruction *instruction);
int						aff_valid(char *command, t_instruction *instruction);
char					*label_extract(char *command);
void					replace_tabs_space(char *command);
void					remove_comments(char *buffer);
int						correct_seperator(char *command, char *op);
void					instruction_size(t_instruction *instructions);
void					ind_size(t_instruction *instructions);
void					dir_size(t_instruction *instructions);
void					reg_size(t_instruction *instructions);
void					codage_size(t_instruction *instructions);
int						label_size(t_instruction *instructions);
int						label_size(t_instruction *instructions);
void					codage_size(t_instruction *instructions);
void					error_handling(int error);
int						get_type(char *command);
void					free_two_d(char **two_d);
char					*command_assist(char *command);
int						all_label_chars(char *arg, int i);
int						all_numbers(char *arg, int i);
void					space_exception(char *command);
void					argument_with_spaces(char *command);
void					encoding(t_instruction *instruction);
char					*concat_hex_string(char *dest, char *src, int len);
char					*put_null(char *byte_code);
char					*put_size(char *byte_code, int size);
char					*put_magic(char *byte_code);
int						save_size(int size);
char					*encode_operations(char *byte_code, t_instruction *i);
char					*encode_arguments(char *byte_code,
						t_instruction *instruction);
int						space_before(char *string);
void					battle(t_players **players, t_cw *data);
unsigned char			*create_arena(void);
void					place_executables(t_players **players,
						unsigned char *arena);
t_carriage				**initialize_carriages(t_players **players,
						unsigned char *arena);
t_carriage				**carriages_array(void);
t_carriage				*carriage_origin(t_players *player,
						unsigned char *arena, int position);
int						is_reg_num(unsigned char reg);
int						single_arg_dir(unsigned int opcode);
void					reverse_carriage_array(t_carriage **carriages,
						int players_count);
int						cycles_before_execution(unsigned int opcode);
void					initialize_registers(t_carriage *carriage);
void					rev_per_two_char(char *s);
int						count_players(t_players **players);
char					*last_player_name(t_players **players);
int						last_player_id(t_players **players);
void					error_message(int errornr);
char					*last_player_live(char *player);
int						number_of_cycles(int update);
int						number_of_live_performed(int update);
int						cycles_to_die(int decrease);
int						number_of_checks(int update);
int						calculate_jump(unsigned int opcode,
						unsigned char *arena, int position);
void					print_arena(unsigned char *arena);
void					print_carriages(t_carriage **carriages);
void					capitalize_atoi(char *tmp);
unsigned char			*save_arena(unsigned char *arena);
t_carriage				**save_carriages(t_carriage **carriages);
void					register_write(t_carriage *carriage,
						int destination_register, int value);
int						register_value(t_carriage *carriage, int reg);
void					carriage_ld_assist(t_carriage *carriage,
						int value, int reg);
void					carriage_st_register(t_carriage *carriage,
						int source_register, int destination_register);
void					carriage_st_register_assist(t_carriage *carriage,
						int source_register, int destination_register);
void					carriage_st_indirect(t_carriage *carriage,
						int source_register, int indirect,
						unsigned char *arena);
void					shift_carriages(t_carriage **saved_carriages);
void					copy_registers(t_carriage *src, t_carriage *dst);
void					carriage_jump(t_carriage *carriage);
void					carriage_live(t_carriage *carriage, int cycle);
void					carriage_ld(t_carriage *carriage, int value, int reg);
void					carriage_ld_assist(t_carriage *carriage,
						int value, int reg);
void					carriage_st(t_carriage *carriage, int source_register,
						int destination_register, int indirect);
void					carriage_st_register(t_carriage *carriage,
						int source_register, int destination_register);
void					carriage_st_register_assist(t_carriage *carriage,
						int source_register, int destination_register);
void					carriage_st_indirect(t_carriage *carriage,
						int source_register, int indirect,
						unsigned char *arena);
void					carriage_add(t_carriage *carriage,
						int reg1, int reg2, int reg3);
void					carriage_sub(t_carriage *carriage, int reg1,
						int reg2, int reg3);
void					carriage_and(t_carriage *carriage, int num1,
						int num2, int reg);
void					carriage_or(t_carriage *carriage, int num1,
						int num2, int reg);
void					carriage_xor(t_carriage *carriage, int num1,
						int num2, int reg);
void					carriage_zjmp(t_carriage *carriage, int direct_value);
void					carriage_ldi(t_carriage *carriage, int distance1,
						int distance2, int reg);
void					carriage_sti(t_carriage *carriage, int distance1,
						int distance2, int reg);
void					carriage_fork(t_carriage *carriage, int distance);
void					shift_carriages(t_carriage **saved_carriages);
void					copy_registers(t_carriage *src, t_carriage *dst);
void					carriage_lld(t_carriage *carriage, int value, int reg);
void					carriage_lldi(t_carriage *carriage, int distance1,
						int distance2, int reg);
void					carriage_lfork(t_carriage *carriage, int distance);
void					carriage_aff(t_carriage *carriage, int reg);
int						valid_register(int reg);
int						extract_4_bytes(int byte_1);
int						extract_2_bytes(int byte_1);
int						extract_1_byte(int byte_1);
void					carriage_command_hub(t_carriage *carriage);
void					carriage_live_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_ld_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_st_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_add_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_sub_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_and_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_or_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_xor_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_zjmp_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_ldi_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_sti_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_fork_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_lld_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_lldi_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_lfork_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_aff_hub(t_carriage *carriage,
						unsigned char *arena);
t_types					*extract_types_3(unsigned char arg_byte);
t_types					*extract_types_2(unsigned char arg_byte);
int						arg_is_a_nbr(char *s);
void					extract_warrior_data(char *argv, t_players *player,
						t_cw *data);
void					check_and_prevent_duplicate_id(t_players *arr,
						int warrior_count);
char					*ft_strrev(char *str);
int						ft_atoi_base(const char *str, int base);
int						all_carriages_count(int update);
void					remove_dead_carriages(t_carriage **carriages,
						int current_cycle, int cycles_to_die);
int						last_player_live_id(int reported_id);
void					print_winner(t_players **players, int winner_id);
int						extract_dir(int byte_1);
int						extract_ind(int byte_1);
int						extract_reg(int byte_1);
void					register_write_assist(t_carriage *carriage,
						int destination_register, int value);
int						register_value_assist(t_carriage *carriage,
						int reg);
void					place_executables(t_players **players,
						unsigned char *arena);
unsigned char			*create_arena(void);
void					introduce_players(t_players **players);
int						battle_execute();
void					battle_execute_assist(t_carriage **carriages);
void					carriage_jump(t_carriage *carriage);
void					carriage_live_hub(t_carriage *carriage,
						unsigned char *arena);
void					carriage_live(t_carriage *carriage, int id);
void					shift_carriages(t_carriage **saved_carriages);
void					copy_registers(t_carriage *src, t_carriage *dst);
void					carriage_command_hub_assist(t_carriage *carriage,
						unsigned char *arena, unsigned int opcode);
void					remove_dead_carriages_assist(int *i,
						t_carriage **carriages, int *count);
int						carriage_and_hub_assist_1(t_carriage *carriage,
						t_types *types, int *arg1, int *temp);
int						carriage_and_hub_assist_2(t_carriage *carriage,
						t_types *types, int *arg1);
void					carriage_and_hub_assist_3(t_carriage *carriage,
						t_types *types, int *arg1);
void					carriage_and_hub_assist_4(t_carriage *carriage,
						t_types *types, int *arg1, int *temp);
int						carriage_ldi_hub_assist_1(t_carriage *carriage,
						t_types *types, int *arg1, int *temp);
int						carriage_ldi_hub_assist_2(t_carriage *carriage,
						t_types *types, int *arg1);
void					carriage_ldi_hub_assist_3(t_carriage *carriage,
						t_types *types, int *arg1);
int						carriage_lldi_hub_assist_1(t_carriage *carriage,
						t_types *types, int *arg1, int *temp);
int						carriage_lldi_hub_assist_2(t_carriage *carriage,
						t_types *types, int *arg1);
void					carriage_lldi_hub_assist_3(t_carriage *carriage,
						t_types *types, int *arg2);
int						carriage_st_hub_assist_1(t_carriage *carriage,
						t_types *types, int *arg2, int *temp);
int						carriage_sti_hub_assist_1(t_carriage *carriage,
						t_types *types, int *arg2, int *temp);
int						carriage_sti_hub_assist_2(t_carriage *carriage,
						t_types *types, int *arg2);
int						carriage_or_hub_assist_1(t_carriage *carriage,
						t_types *types, int *arg1, int *temp);
int						carriage_or_hub_assist_2(t_carriage *carriage,
						t_types *types, int *arg1);
void					carriage_or_hub_assist_3(t_carriage *carriage,
						t_types *types, int *arg1);
void					carriage_or_hub_assist_4(t_carriage *carriage,
						t_types *types, int *arg1, int *temp);
int						carriage_xor_hub_assist_1(t_carriage *carriage,
						t_types *types, int *arg1, int *temp);
int						carriage_xor_hub_assist_2(t_carriage *carriage,
						t_types *types, int *arg1);
void					carriage_xor_hub_assist_3(t_carriage *carriage,
						t_types *types, int *arg1);
void					carriage_xor_hub_assist_4(t_carriage *carriage,
						t_types *types, int *arg1, int *temp);
int						aff_calculate_jump(unsigned char *arena,
						int position);
t_players				**save_players(t_players **players);
void					print_carriage(t_carriage *carriages);
void					carriage_sti_assist(int source_register_value,
						int target_location, unsigned char *arena);
void					kill_carriages(t_carriage **carriages);
int						carriage_ld_hub_assist(t_carriage *carriage);
int						carriage_ldi_hub2(t_carriage *carriage,
						t_types *types, int *arg2);
int						carriage_lld_hub_assist(t_carriage *carriage);
int						carriage_and_hub2(t_carriage *carriage,
						t_types *types, int *arg2, int *temp);
int						carriage_ldi_hub2(t_carriage *carriage,
						t_types *types, int *arg2);
int						carriage_lldi_hub2(t_carriage *carriage,
						t_types *types, int *arg2);
int						carriage_xor_hub2(t_carriage *carriage,
						t_types *types, int *arg2, int *temp);
int						carriage_sti_hub2(t_carriage *carriage,
						t_types *types, int *arg1);
int						carriage_or_hub2(t_carriage *carriage,
						t_types *types, int *arg2, int *temp);
void					battle_finished(t_cw *data, t_players **players);
void					battle_assist(t_players **players,
						unsigned char *arena);
void					battle_execute_decrement(void);
int						save_l_flag(t_cw *data);
void					carriage_jump_free(t_carriage *carriage,
						t_types *types);
#endif
