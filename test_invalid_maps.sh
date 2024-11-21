#!/bin/bash
# Define color codes
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"  # No color (reset)
EXECUTABLE="./Cub3D"  # Path to executable

EXPECTED_EXIT_CODE=1
#Directory
DIR="maps/invalid/"

ERRCOUNT=0
VALERRCOUNT=0

VALGRIND="valgrind --leak-check=full --error-exitcode=2"
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
		"map_1_invalid.cub"
		"map_2_invalid.cub"
		"map_3_invalid.cub"
		"map_4_invalid.cub"
		"map_5_invalid.cub"
		"map_6_invalid.cub"
		"map_7_invalid.cub"
		"map_8_invalid.cub"
		"map_9_invalid.cub"
		"map_10_invalid.cub"
		"map_11_invalid.cub"
		"map_12_invalid.cub"
)

clear
echo "Invalid map test"
for FILE in "${INPUT_FILES[@]}"; do
    echo "Map: $FILE"
    $EXECUTABLE "$DIR$FILE"
    EXIT_CODE=$?
    # Check the result and print a message
    if [[ $EXIT_CODE -eq $EXPECTED_EXIT_CODE ]]; then
		echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}KO${NC}"
		echo $FILE >> kos
		ERRCOUNT=$((ERRCOUNT + 1))
    fi
    $VALGRIND $EXECUTABLE "$DIR$FILE" > valgrindout.txt 2>&1
    EXIT_CODE=$?
    # Check the result and print a message
    if [ $EXIT_CODE -eq 2 ]; then
        echo -e "${RED}MKO${NC}"
		echo $FILE >> kos 
		cat valgrindout.txt
		VALERRCOUNT=$((VALERRCOUNT + 1))
    else
		echo -e "${GREEN}MOK${NC}"
    fi
	rm valgrindout.txt
    echo "---------------------------"
done

echo "---------------------------"
echo "Summary:"
if [ $ERRCOUNT -eq 0 ]; then
    echo -e "${GREEN}\tNo Errors${NC}"
else
	echo -e "\t${RED}$ERRCOUNT${NC} KO's"
fi
if [ $VALERRCOUNT -eq 0 ]; then
    echo -e "\t${GREEN}No memory leaks${NC}"
else
	echo -e "\t${RED}$VALERRCOUNT${NC} leak(s)"
fi
cat kos
rm kos
echo "---------------------------"
echo "---------------------------"
