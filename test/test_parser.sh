style_header0="\e[32;1m"
style_header1="\e[32;2m"
style_reset="\e[0m"

test_files=(
	"test/maps/null.cub"		# Nonexistent file
	"test/maps/test00.cub3d"	# Bad file extension
	"test/maps/test00.cub"		# Bad colour specification
	"test/maps/test01.cub"		# Unopenable texture
	"test/maps/test02.cub"		# Doubly defined colour
	"test/maps/test03.cub"		# Doubly defined texture
	"test/maps/test04.cub"		# Missing colour
	"test/maps/test05.cub"		# Missing texture
	"test/maps/test06.cub"		# Invalid object
	"test/maps/test07.cub"		# Unenclosed level
	"test/maps/test08.cub"		# Missing player position
	"test/maps/test09.cub"		# Double player position
	"test/maps/test10.cub"		# Player in unenclosed position
)

cd ..

echo -e "${style_header0}Testers for cub3d: level parser${style_reset}" 

for file in ${test_files[@]}; do
	echo -e "${style_header1}     Test: $file ${style_reset}"
	./cub3d $file
done
