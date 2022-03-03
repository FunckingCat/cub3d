#ifndef HOOKS_H
# define HOOKS_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../state/state.h"
# include "../constants.h"
# include "../error/error.h"
# include "../render/render.h"
# include "../vector/vector.h"

void	set_hooks(t_state *state);

// # define KEYPRESS	2
// # define KEYEXIT	17
// # define A_KEY		0
// # define S_KEY		1
// # define D_KEY		2
// # define W_KEY		13
// # define ESC 		53

# define KEYEXIT	17
# define KEYPRESS	2
# define W_KEY		119
# define A_KEY		97
# define S_KEY		115
# define D_KEY		100
# define Q_KEY		113
# define E_KEY		101
# define ESC 		65307

#endif