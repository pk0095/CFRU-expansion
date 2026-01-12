import re

# Input species defines as a multi-line string
species_defines = """
#define SPECIES_ARCEUS_FIGHT 0x2D0
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
"""  # Replace this with your original text or keep as is

# Regex to match each define
pattern = re.compile(r"#define SPECIES_([A-Z0-9_]+)\s+0x([0-9A-F]+)")

def format_name(raw_name):
    parts = raw_name.lower().split('_')
    return ''.join(part.capitalize() for part in parts)

# Process and print
for match in pattern.finditer(species_defines):
    raw_name = match.group(1)
    hex_value = match.group(2)
    dec_value = int(hex_value, 16)
    name = format_name(raw_name)
    print(f"extern const u16 gFollowerMonPic2{dec_value}_{name}ShinyPal[];")
