import re

# Set your custom starting hex ID here
start_hex_id = 0x17A6

# Your input species map — paste it below
input_species_block = """
#define SPECIES_ARCEUS_FLYING 0x2D1
#define SPECIES_ARCEUS_POISON 0x2D2
#define SPECIES_ARCEUS_GROUND 0x2D3
#define SPECIES_ARCEUS_ROCK 0x2D4
#define SPECIES_ARCEUS_BUG 0x2D5
#define SPECIES_ARCEUS_GHOST 0x2D6
#define SPECIES_ARCEUS_STEEL 0x2D7
#define SPECIES_ARCEUS_FIRE 0x2D8
#define SPECIES_ARCEUS_WATER 0x2D9
#define SPECIES_ARCEUS_GRASS 0x2DA
#define SPECIES_ARCEUS_ELECTRIC 0x2DB
#define SPECIES_ARCEUS_PSYCHIC 0x2DC
#define SPECIES_ARCEUS_ICE 0x2DD
#define SPECIES_ARCEUS_DRAGON 0x2DE
#define SPECIES_ARCEUS_DARK 0x2DF
"""

# Pattern to extract species inside square brackets
pattern = re.compile(r"#define SPECIES_([A-Z0-9_]+)")

# Generate new formatted lines
lines = input_species_block.strip().splitlines()

for i, line in enumerate(lines):
    match = pattern.search(line)
    if match:
        species = match.group(1)
        hex_id = start_hex_id + i
        print(f"    [SPECIES_{species}] = 0x{hex_id:04X},")
