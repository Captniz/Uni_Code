import toml

def convert_toml_to_nix(toml_dict):
    """
    Recursively converts a Python dictionary from a parsed TOML file into Nix config syntax.
    """
    def nix_format(value):
        if isinstance(value, dict):
            return "{\n" + "\n".join(f"  {k} = {nix_format(v)};" for k, v in value.items()) + "\n}"
        elif isinstance(value, list):
            return "[ " + " ".join(nix_format(v) for v in value) + " ]"
        elif isinstance(value, str):
            return f'"{value}"'
        elif isinstance(value, (int, float, bool)):
            return str(value).lower()
        else:
            raise ValueError(f"Unsupported value type: {type(value)}")

    return nix_format(toml_dict)

def toml_to_nix(toml_file, nix_file):
    """
    Converts a TOML file to a Nix configuration file.
    """
    try:
        # Read the TOML file
        with open(toml_file, 'r') as f:
            toml_data = toml.load(f)
        
        # Convert the TOML data to Nix format
        nix_config = convert_toml_to_nix(toml_data)

        # Write the Nix configuration to a file
        with open(nix_file, 'w') as f:
            f.write(nix_config)
        
        print(f"Successfully converted {toml_file} to {nix_file}")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    import argparse

    # Argument parsing
    parser = argparse.ArgumentParser(description="Convert a TOML file to a Nix config file.")
    parser.add_argument("input", help="Path to the input TOML file.")
    parser.add_argument("output", help="Path to the output Nix file.")

    args = parser.parse_args()

    # Perform the conversion
    toml_to_nix(args.input, args.output)
