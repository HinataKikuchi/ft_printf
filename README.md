# ft_printf

42 subject

First Circle

# what should we do?(どんな課題？)

Make printf func by using write func.

# Directory Structure(ファイル構成)

```
ft_printf
├── README.md
└── srcs
   ├── calc_hex.c
   ├── format_deal.c
   ├── ft_printf.c
   ├── ft_printf.h
   ├── ft_utils.c
   ├── ft_utoa.c
   ├── ft_write_char.c
   ├── ft_write_digit.c
   ├── ft_write_large_hex.c
   ├── ft_write_pointer.c
   ├── ft_write_small_hex.c
   ├── ft_write_sp_zero.c
   ├── ft_write_string.c
   ├── ft_write_unsigned.c
   ├── libft
   │  ├── ft_atoi.c
   │  ├── ft_bzero.c
   │  ├── ft_calloc.c
   │  ├── ft_isalnum.c
   │  ├── ft_isalpha.c
   │  ├── ft_isascii.c
   │  ├── ft_isdigit.c
   │  ├── ft_isprint.c
   │  ├── ft_itoa.c
   │  ├── ft_memccpy.c
   │  ├── ft_memchr.c
   │  ├── ft_memcmp.c
   │  ├── ft_memcpy.c
   │  ├── ft_memmove.c
   │  ├── ft_memset.c
   │  ├── ft_putchar_fd.c
   │  ├── ft_putendl_fd.c
   │  ├── ft_putnbr_fd.c
   │  ├── ft_putstr_fd.c
   │  ├── ft_split.c
   │  ├── ft_strchr.c
   │  ├── ft_strdup.c
   │  ├── ft_strjoin.c
   │  ├── ft_strlcat.c
   │  ├── ft_strlcpy.c
   │  ├── ft_strlen.c
   │  ├── ft_strmapi.c
   │  ├── ft_strncmp.c
   │  ├── ft_strnstr.c
   │  ├── ft_strrchr.c
   │  ├── ft_strtrim.c
   │  ├── ft_substr.c
   │  ├── ft_tolower.c
   │  ├── ft_toupper.c
   │  ├── libft.h
   │  └── Makefile
   └── Makefile
   ```

# Status(課題の進捗)

🎉DONE!!!🥳🎉

[![hkikuchi's 42 ft_printf Score](https://badge42.vercel.app/api/v2/cl2yp504l006109mh3mmv9c3c/project/2063037)](https://github.com/JaeSeoKim/badge42)


# HOW TO MOVE IT?(ENGLISH)
日本語での使用方法の説明は[こちら](#%E3%81%A9%E3%81%86%E3%82%84%E3%81%A3%E3%81%A6%E5%8B%95%E3%81%8B%E3%81%99%E3%81%8B)



1. Git clone this repository to your rocal environment. (If you already git user and could reach here, then you know this command.)

```
git clone git@github.com:HinataKikuchi/ft_printf.git
```

2. JUST DO MAKE.

```
$ cd ./ft_printf
$ make -C ./srcs
```

3. Archive file(named ```libprintf.a```) will appear in srcs, when successfully Compiled.

4. If you want to use ft_printf funcs in your dir, examples bellow.

```
$ gcc -I./ft_printf/srcs -L./ft_printf/srcs -lprintf <your_source_name>
```

5. FIN.


# どうやって動かすか？

1. このレポジトリをクローンしてください。

```
git clone git@github.com:HinataKikuchi/ft_printf.git
```

2. メイクしてもろて

```
$ cd ./ft_printf
$ make -C ./srcs
```

3. コンパイルに成功するとアーカイブファイル(```libprintf.a```って名前のやつ)がsrcs下にできます。

4. もしft_printf関数を自分のファイルで使いたいときは以下の例のように使ってください。

```
$ gcc -I./ft_printf/srcs -L./ft_printf/srcs -lprintf <your_source_name>
```

5. おーわり！
