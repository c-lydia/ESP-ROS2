"""Custom rinohtype style for Wall-E documentation."""

from rinoh.style import StyleSheet
from rinoh.color import Color

# Create a custom stylesheet
stylesheet = StyleSheet('wall-e')

# Color palette
PRIMARY_BLUE = Color(0x2980B9)
DARK_BLUE = Color(0x1a5490)
ACCENT_TEAL = Color(0x16a085)
TEXT_DARK = Color(0x2c3e50)
TEXT_GRAY = Color(0x7f8c8d)
LIGHT_BG = Color(0xecf0f1)
CODE_BG = Color(0x34495e)
CODE_TEXT = Color(0xecf0f1)

# Paragraph styles
stylesheet['paragraph'] = dict(
    font_size=10,
    line_spacing=1.3,
    text_color=TEXT_DARK,
    space_above=6,
    space_below=6,
)

# Heading styles with professional formatting
stylesheet['heading'] = dict(
    font_weight='bold',
    text_color=DARK_BLUE,
    space_above=12,
    space_below=6,
)

stylesheet['h1'] = dict(
    base='heading',
    font_size=28,
    text_color=PRIMARY_BLUE,
    space_above=18,
    space_below=12,
)

stylesheet['h2'] = dict(
    base='heading',
    font_size=20,
    text_color=DARK_BLUE,
    space_above=14,
    space_below=8,
)

stylesheet['h3'] = dict(
    base='heading',
    font_size=14,
    text_color=ACCENT_TEAL,
    space_above=10,
    space_below=6,
)

stylesheet['h4'] = dict(
    base='heading',
    font_size=12,
    text_color=TEXT_DARK,
)

# Code formatting
stylesheet['literal'] = dict(
    font_name='monospace',
    font_size=9,
    text_color=CODE_TEXT,
    background_color=CODE_BG,
)

# Lists
stylesheet['bullet list'] = dict(
    space_above=6,
    space_below=6,
)

stylesheet['enumerated list'] = dict(
    space_above=6,
    space_below=6,
)

# Block quotes
stylesheet['block quote'] = dict(
    margin_left=18,
    text_color=TEXT_GRAY,
)

# Tables
stylesheet['table'] = dict(
    space_above=8,
    space_below=8,
)

