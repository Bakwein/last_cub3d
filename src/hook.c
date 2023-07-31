/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:02:34 by bmerchin          #+#    #+#             */
/*   Updated: 2023/07/31 15:14:56 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_key_hook2(int keycode, t_data *data)
{
	if (keycode == KEY_DOOR && BONUS) //40-k
		close_door(data);
	if (keycode == KEY_MOUSE && BONUS && data->mouse_flag == 0)
		data->mouse_flag = 1;
	else if (keycode == KEY_MOUSE && BONUS && \
		data->mouse_flag == 1)
		data->mouse_flag = 0;
	return (0);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_FORWARD) //13-w
		data->forward = 1;
	if (keycode == KEY_BACKWARD) //1-s
		data->backward = 1;
	if (keycode == KEY_RIGHT) //2-d
		data->right = 1;
	if (keycode == KEY_LEFT) //0-a
		data->left = 1;
	if (keycode == KEY_TURN_LEFT) //124-yön tusu sag
		data->turn_left = 1;
	if (keycode == KEY_TURN_RIGHT) // 123-yön tusu sol
		data->turn_right = 1;
	if (keycode == KEY_CROUCH && BONUS) //8-c
		data->crouch = -30;
	if (keycode == KEY_ESCAPE) // 53-esc
		data->escape = 1;
	if (keycode == KEY_ATTACK && BONUS && data->attack == 0) //257-shift
		data->attack = 30;
	else if (keycode == KEY_ATTACK && BONUS) //cooldown
		printf("You have still %d frames of cooldown left\n", data->attack);
	if (keycode == KEY_SPRINT && BONUS) //126-yön tusu ust
		data->sprint = 1;
	ft_key_hook2(keycode, data);
	return (0);
}

int	ft_key_unhook(int keycode, t_data *data)
{
	if (keycode == KEY_FORWARD)
		data->forward = 0;
	if (keycode == KEY_BACKWARD)
		data->backward = 0;
	if (keycode == KEY_RIGHT)
		data->right = 0;
	if (keycode == KEY_LEFT)
		data->left = 0;
	if (keycode == KEY_TURN_LEFT)
		data->turn_left = 0;
	if (keycode == KEY_TURN_RIGHT)
		data->turn_right = 0;
	if (keycode == KEY_CROUCH)
		data->crouch = 0;
	if (keycode == KEY_ESCAPE)
		data->escape = 0;
	if (keycode == KEY_SPRINT)
		data->sprint = 0;
	return (0);
}
