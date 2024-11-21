#!/bin/bash
# Define color codes
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"  # No color (reset)
EXECUTABLE="./Cub3D"  # Path to executable

EXPECTED_EXIT_CODE=1
#Directory
DIR="maps/invalid/"
# list of map files
INPUT_FILES=(
		"colors_arg_missing.cub"
		"empty.cub"
		"map_middle.cub"
		"player_missing.cub"
		"textures_no_permission.cub"
		"wall_hole_north.cub"
		"colors_missing.cub"
		"extension_none"
		"map_missing.cub"
		"textures_duplicate.cub"
		"textures_none.cub"
		"wall_hole_south.cub"
		"colors_none.cub"
		"extension_wrong.club"
		"player_duplicate.cub"
		"textures_invalid.cub"
		"textures_wrong_format.cub"
		"wall_hole_west.cub"
		"colors_wrong_RGB_range.cub"
		"map_first.cub"
		"player_edge.cub"
		"textures_missing.cub"
		"wall_hole_east.cub"
		"wall_none.cub"
)

for FILE in "${INPUT_FILES[@]}"; do
    echo "Map: $FILE"

    $EXECUTABLE "$DIR$FILE"
    EXIT_CODE=$?
    # Check the result and print a message
    if [[ $EXIT_CODE -eq $EXPECTED_EXIT_CODE ]]; then
		echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}KO${NC}"
    fi
    echo "---------------------------"
done
