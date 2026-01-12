import re

# Starting hex ID
start_id_hex = 0x16A7

# Your species define list
species_defines = """
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
"""  # Paste your #define list here

# Regex to capture species names
pattern = re.compile(r"#define SPECIES_([A-Z0-9_]+)\s+0x[0-9A-Fa-f]+")

def format_name(raw_name):
    parts = raw_name.lower().split('_')
    return ''.join(part.capitalize() for part in parts)

# Generate output
for i, match in enumerate(pattern.finditer(species_defines)):
    raw_name = match.group(1)
    name = format_name(raw_name)
    hex_id = start_id_hex + i
    print(f"    MON_OW_OBJECT_GRAPHICS_64({hex_id:X}, {name})")
