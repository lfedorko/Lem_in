#include "../corewar_vm.h"

void live_com(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	int player;

	player = arg->param[0] * -1;
	if (player > 0 && player <= ms->num_of_players)
	{
		ms->winner = player;
		ms->players[player - 1].last_live = ms->total_cycle;
		(ms->players[player - 1].live_flag)++;
	}
	(ms->live_current_per)++;
	(pr->live_flag)++;
}