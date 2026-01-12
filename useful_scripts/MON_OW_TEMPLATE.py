import re

# Input species defines as a multi-line string
species_defines = """
#define SPECIES_ROTOM_HEAT 0x2C9
#define SPECIES_ROTOM_WASH 0x2CA
#define SPECIES_ROTOM_FROST 0x2CB
#define SPECIES_ROTOM_FAN 0x2CC
#define SPECIES_ROTOM_MOW 0x2CD
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
    print(f"MON_OW_TEMPLATE_32x32_FRAMES(0{dec_value},{name})")
