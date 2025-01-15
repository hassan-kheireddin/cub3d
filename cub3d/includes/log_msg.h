
#ifndef LOG_MSG_H
# define LOG_MSG_H

# define DEF			"\033[0;39m"
# define GRAY			"\033[0;90m"
# define RED			"\033[0;91m"
# define GREEN			"\033[0;92m"
# define YELLOW			"\033[0;93m"
# define BLUE			"\033[0;94m"
# define MAGENTA		"\033[0;95m"
# define CYAN			"\033[0;96m"
# define WHITE			"\033[0;97m"

# define NO				0
# define YES 			1

# define CUB 			1
# define XPM			2

# define TEXTURE		1
# define COLOR			2

# define NORTH			1
# define SOUTH			2
# define EAST			3
# define WEST			4
# define FLOOR			5
# define CEILING		6

# define SPAWN_CHARS	"NSEW"
# define VALID_CHARS	" 01NSEW"
# define SPLIT_RGB		" ,"

# define ERR_ARGS		"Invalid number of arguments"

# define ERR_CUB		"Invalid input file name"
# define ERR_CUB_EXT	"Input file must be .cub"
# define ERR_CUB_OPEN	"Couldn't open input file"

# define ERR_XPM		"Invalid texture file name"
# define ERR_XPM_EXT	"Asset file must be .xpm"
# define ERR_XPM_OPEN	"Couldn't open texture file"
# define ERR_XPM_RPT	"Has repeated textures in this input file"
# define ERR_XPM_CALL	"Has repeated textures calls in this input file"
# define ERR_TEXTURE	"Invalid texture file"

# define ERR_COLOR_FMT	"Color format must be R,G,B"
# define ERR_COLOR_NUM	"Colors must have only positive numbers"
# define ERR_COLOR_RANG "Colors must be between 0 and 255"
# define ERR_COLOR_CALL	"Has repeated colors calls in this input file"

# define ERR_INVALID	"The input file has invalid parameters"
# define ERR_PARAMS		"The input file doesn't have all necessary parameters"

# define ERR_MAP_EMPTY	"Map is not configured correctly"
# define ERR_MAP_WALLS	"The map isn't well surrounded by walls"
# define ERR_MAP_CHARS	"Invalid character in map"
# define ERR_MAP_MSPAWN	"Multiple spawn points"
# define ERR_MAP_NSPAWN	"No spawn point"

# define WIN_TITLE		"Cub3D"
# define TEXTURE_SIZE	64

# define ONE			1
# define ZERO			0
# define PLANE			0.66

# define MOV			0.6
# define ROT			0.5

# define KEY_ESC		65307
# define LEFT			65361
# define RIGHT			65363
# define W				119
# define A				97
# define S				115
# define D				100

#endif