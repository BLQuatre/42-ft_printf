<p align="center">
	<a href="https://github.com/ayogun/42-project-badges"><img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/ft_printfm.png" alt="ft_printf badge (Bonus)"/></a>
</p>

<h1 align="center">
	ft_printf
</h1>

<p align="center">
	<b><i>Because ft_putnbr() and ft_putstr() aren’t enough </i></b><br>
	<b><i>By <a href="https://github.com/BLQuatre">BLQuatre</a></i></b><br>
</p>

## 🛠️ Usage

#### Building the project
To build the project, just run the command
```sh
make
```

To use it, you can includes it in your library, add flag `-Iincludes` to include header files

#### This ft_printf support
| Format    | Display what            | Example                               | Output on STDOUT |
| :---:     | :---:                   | :---:                                 | :---:            |
| `%c`      | Single char             | `ft_printf("%c\n", 'H')`              | `H`              |
| `%s`      | String                  | `ft_printf("%s\n", "Hello World!")`   | `Hello World!`   |
| `%d`/`%i` | Decimal/Integer         | `ft_printf("%d %i\n", 42, 29)`        | `42 29`          |
| `%u`      | Unsigned Integer        | `ft_printf("%u\n", 42)`               | `42`             |
| `%x`      | Hexadecimal (lowercase) | `ft_printf("%x\n", 42)`               | `2a`             |
| `%X`      | Hexadecimal (uppercase) | `ft_printf("%X\n", 42)`               | `2A`             |
| `%p`      | Adress                  | `ft_printf("%p\n", &var)`             | `0x2a2a2a2a`     |
| `%%`      | Percent                 | `ft_printf("100%%\n")`                | `100%`           |

#### Supported printf flags
- `#`, `Space`, `+`, `-`, `0`, `.`
