import re

# Starting hex ID (user-defined)
start_hex_id = 0x16A7
start_hex_id_poke = 0x2D0

# Input species list
input_species_block = """
#define SPECIES_ARCEUS 0x2D0
#define SPECIES_ARCEUS 0x2D1
#define SPECIES_ARCEUS 0x2D2
#define SPECIES_ARCEUS 0x2D3
#define SPECIES_ARCEUS 0x2D4
#define SPECIES_ARCEUS 0x2D5
#define SPECIES_ARCEUS 0x2D6
#define SPECIES_ARCEUS 0x2D7
#define SPECIES_ARCEUS 0x2D8
#define SPECIES_ARCEUS 0x2D9
#define SPECIES_ARCEUS 0x2DA
#define SPECIES_ARCEUS 0x2DB
#define SPECIES_ARCEUS 0x2DC
#define SPECIES_ARCEUS 0x2DD
#define SPECIES_ARCEUS 0x2DE
#define SPECIES_ARCEUS 0x2DF
"""

# Regex to extract species names
pattern = re.compile(r"#define SPECIES_([A-Z0-9_]+)")

# Process each line
species_names = []
for line in input_species_block.strip().splitlines():
    match = pattern.search(line)
    if match:
        species_names.append(match.group(1))

# Output lines with incremented hex IDs
for i, species in enumerate(species_names):
    hex_id = start_hex_id + i
    hex_id_2 = start_hex_id_poke + i
    print(f"        {{gFollowerMonPic0{hex_id_2}_{species.title()}Pal, 0x{hex_id:04X}}},")
