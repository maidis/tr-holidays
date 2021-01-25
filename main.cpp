#include "date/date.h"
#include "date/islamic.h"

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace date;
using namespace std::chrono;

// https://github.com/HowardHinnant/date/wiki/FAQ
constexpr year_month_day operator+(const year_month_day& ymwd, const date::days& dd) noexcept
{
    return year_month_day{date::sys_days{ymwd} + dd};
}

// https://github.com/HowardHinnant/date/wiki/Boost-datetime-Examples-Translated#Print_Holidays
std::vector<std::pair<date::sys_days, std::string>> generate_holidays(date::year y)
{
    std::vector<std::pair<date::sys_days, std::string>> holidays;
    // https://github.com/KDE/kholidays/blob/master/holidays/plan2/holiday_tr_en-gb
    holidays.push_back(std::make_pair(y/jan/1, "New Year's Day"));
    holidays.push_back(std::make_pair(y/apr/23, "National Sovereignty and Children's Day"));
    holidays.push_back(std::make_pair(y/may/1, "Labour and Solidarity Day"));
    holidays.push_back(std::make_pair(y/may/19, "Commemoration of Atatürk, Youth and Sports Day"));
    // Became a national holiday after 15 Jul 2016 coup d'etat attempt
    // https://github.com/dr-prodigy/python-holidays/blob/master/holidays/countries/turkey.py
    if(y > 2016_y)
    {
        holidays.push_back(std::make_pair(y/jul/15, "Democracy and National Unity Day"));
    }
    holidays.push_back(std::make_pair(y/aug/30, "Victory Day"));
    holidays.push_back(std::make_pair(y/oct/29, "Republic Day"));

    // TODO: can be a false assumption, find a better way
    auto ymd = y/jan/1;
    auto jymd = islamic::year_month_day{ymd};
    auto y2 = jymd.year();

    holidays.push_back(std::make_pair(y2/10/1, "Ramadan Feast"));
    holidays.push_back(std::make_pair(y2/10/2, "Ramadan Feast Holiday"));
    holidays.push_back(std::make_pair(y2/10/3, "Ramadan Feast Holiday"));
    holidays.push_back(std::make_pair(y2/12/10, "Sacrifice Feast")); // Sacrifice Feast, public religious on hijri thualhijjah 10 length 4
    holidays.push_back(std::make_pair(y2/12/11, "Sacrifice Feast Holiday"));
    holidays.push_back(std::make_pair(y2/12/12, "Sacrifice Feast Holiday"));
    holidays.push_back(std::make_pair(y2/12/13, "Sacrifice Feast Holiday"));

    std::sort(holidays.begin(), holidays.end());
    return holidays;
}

int main()
{
    std::cout << "📅🎅🥳🎉 Welcome to the Holiday Calendar 🎊🍬🐄🌞\n";
    // TODO: check for bad/nonexistent dates like 2021-06-31
    // TODO: add supoort for more dates like 2021/01/01, 2021.01.01, 2021 01 01, 31.12.2021...
    year_month_day day1;
    std::cout << "Please write first date as YYYY-MM-DD: ";
    std::cin >> parse("%F", day1);

    year_month_day day2;
    // TODO: second cin not working normally, why?
    // https://stackoverflow.com/questions/19390059/program-skips-second-cin/24376769
    std::cin.get();
    std::cout << "Please write second date as same format: ";
    std::cin >> parse("%F", day2);

    //constexpr auto startDate = 2020_y/jan/1;
    //auto endDate = 2021_y/jan/1;

    auto x = day1;

    std::vector<date::sys_days> days{};
    while (x <= day2)
    {
        days.push_back(x);
        x = year_month_day{x + date::days{1}};
    }

    //define a collection of holidays fixed by month and day
    std::vector<std::pair<date::sys_days, std::string>> holidays{};

    year dt1 = day1.year();
    year dt2 = day2.year();
    while(dt1 <= dt2)
    {
        auto temp = generate_holidays(dt1);
        holidays.insert( holidays.end(), temp.begin(), temp.end() );
        ++dt1;
    }

    int holidaySize{};
    std::cout << "Here are your holidays:\n";
    for (const auto& d : holidays)
    {
        // https://stackoverflow.com/questions/44831793/what-is-the-difference-between-vector-back-and-vector-end
        if ((d.first <= days.back()) && (d.first >= days.front()))
        {
            std::cout << format("%d.%m.%Y", d.first) << " " << weekday{d.first} << " - " << d.second << "\n";
            ++holidaySize;
        }
    }
    std::cout << "Number Holidays: " << holidaySize << '\n';
}
