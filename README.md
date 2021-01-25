# tr-holidays

[tr-holidays](https://github.com/maidis/tr-holidays) is largely inspired by [melike35/holidays-between-2-days](https://github.com/melike35/holidays-between-2-days), gets two dates from user and lists all holidays between these dates.

For now, this is just a simple example project and lists holidays in Turkey. Other countries may be supported when C++ has a holiday library like [python-holidays](https://github.com/dr-prodigy/python-holidays).

This project could exist thanks to [HowardHinnant/date](https://github.com/HowardHinnant) library. I would also like to mention KDE's [KHolidays](https://github.com/KDE/kholidays) library.

## Build

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./tr-holidays
```

## Usage

```bash
📅🎅🥳🎉 Welcome to the Holiday Calendar 🎊🍬🐄🌞
Please write first date as YYYY-MM-DD: 2021-01-01
Please write second date as same format: 2021-05-01
Here are your holidays:
01.01.2021 Fri - New Year's Day
23.04.2021 Fri - National Sovereignty and Children's Day
01.05.2021 Sat - Labour and Solidarity Day
Number Holidays: 3
```
