files = [
    "get_next_line.c",
    "get_next_line.h",
    "get_next_line_utils.c",
    "get_next_line_bonus.c",
    "get_next_line_bonus.h",
    "get_next_line_utils_bonus.c"
]

for f in files:
    try:
        with open(f, "rb") as file:
            data = file.read()
            for i, b in enumerate(data):
                if b > 127:  # non-ASCII
                    # compute line number
                    file.seek(0)
                    line_number = file.read(i).count(b'\n') + 1
                    print(f"{f}: byte {b:#x} at position {i} (line {line_number})")
                    break
    except FileNotFoundError:
        print(f"{f} not found!")