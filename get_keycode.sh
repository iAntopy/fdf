# Give this script the name of a key you would want to hook events to as argument,
# and the script will try to find it in the KC_REFS file.
# Used as a guide to find MACRO defines for relevent keycodes.

KC_REFS="keycodesdef.h"

if test ! -f "$KC_REFS"
	then
	echo "Keycodes list file NOT PRESENT in directory."
	exit 0
fi

echo "((===================<| MATCHING CODES FOUND |>=====================))"
grep "^#define" keysymdef.h | grep --ignore-case $1 |
awk -Wposix -F' ' 'BEGIN {printf("((\t%-30s| %-12s | %-12s ))\n((__________________________________________________________________))\n", "  NAME", "  HEX CODE", "  DEC CODE")} {printf("((\t%-30s|  %-12s|  %-12d))\n", $2, $3, $3)}'

echo "((==================================================================))\n\n"

#set -o noglob
#echo "$KC_FOUND" # | awk -F"#define" '{print $2}')
#set +o noglob



#if [ -z "$KC_FOUND" ]
#then
#	echo "No keycode entry refering to $1."
#else
#	KC_NAME=$(echo $KC_FOUND | cut -d" " -f2)
#	KC_HEX=$(echo $KC_FOUND | cut -d" " -f3)
#	KC_DEC=$(echo $(printf "%d" $KC_HEX))
#	echo "Keycode found :" # "	dec: $((16#$(awk -F ' ' '{print $(NF)}')))"
#	echo "	NAME	: $KC_NAME"
#	echo "	HEX	: $KC_HEX"
#	echo "	DEC	: $KC_DEC"
#fi
