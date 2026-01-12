import re

# Your input species map — paste it below
input_species_block = """
#define SPECIES_ROTOM_HEAT 0x2C9
#define SPECIES_ROTOM_WASH 0x2CA
#define SPECIES_ROTOM_FROST 0x2CB
#define SPECIES_ROTOM_FAN 0x2CC
#define SPECIES_ROTOM_MOW 0x2CD
"""

# Set your starting index for the array
start_index = 174


# Regex pattern to extract species name
pattern = re.compile(r"#define SPECIES_([A-Z0-9_]+)")

# Clean and capitalize species names (handle underscores properly)
def format_species_name(raw):
    return ''.join(part.capitalize() for part in raw.lower().split('_'))

lines = input_species_block.strip().splitlines()

for i, line in enumerate(lines):
    match = pattern.search(line)
    if match:
        species_name = format_species_name(match.group(1))
        index = start_index + i
        print(f"\t&gFollowerMonGfxTable2[{index}], // {species_name}")
