#ifndef MEETUP_H
#define MEETUP_H

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

enum Weekday {
    Monday = 0, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

class scheduler {
public:
    scheduler(int m, int y) : month(m), year(y) {}

    // Existing methods (monteenth, first_* etc.)
    boost::gregorian::date monteenth() const { return find_teenth(Monday); }
    boost::gregorian::date tuesteenth() const { return find_teenth(Tuesday); }
    boost::gregorian::date wednesteenth() const { return find_teenth(Wednesday); }
    boost::gregorian::date thursteenth() const { return find_teenth(Thursday); }
    boost::gregorian::date friteenth() const { return find_teenth(Friday); }
    boost::gregorian::date saturteenth() const { return find_teenth(Saturday); }
    boost::gregorian::date sunteenth() const { return find_teenth(Sunday); }

    boost::gregorian::date first_monday() const { return find_nth_weekday(1, Monday); }
    boost::gregorian::date first_tuesday() const { return find_nth_weekday(1, Tuesday); }
    boost::gregorian::date first_wednesday() const { return find_nth_weekday(1, Wednesday); }
    boost::gregorian::date first_thursday() const { return find_nth_weekday(1, Thursday); }
    boost::gregorian::date first_friday() const { return find_nth_weekday(1, Friday); }
    boost::gregorian::date first_saturday() const { return find_nth_weekday(1, Saturday); }
    boost::gregorian::date first_sunday() const { return find_nth_weekday(1, Sunday); }

    boost::gregorian::date second_monday() const { return find_nth_weekday(2, Monday); }
    boost::gregorian::date second_tuesday() const { return find_nth_weekday(2, Tuesday); }
    boost::gregorian::date second_wednesday() const { return find_nth_weekday(2, Wednesday); }
    boost::gregorian::date second_thursday() const { return find_nth_weekday(2, Thursday); }
    boost::gregorian::date second_friday() const { return find_nth_weekday(2, Friday); }
    boost::gregorian::date second_saturday() const { return find_nth_weekday(2, Saturday); }
    boost::gregorian::date second_sunday() const { return find_nth_weekday(2, Sunday); }

    // New Methods: Third, Fourth, Last Weekdays
    boost::gregorian::date third_monday() const { return find_nth_weekday(3, Monday); }
    boost::gregorian::date third_tuesday() const { return find_nth_weekday(3, Tuesday); }
    boost::gregorian::date third_wednesday() const { return find_nth_weekday(3, Wednesday); }
    boost::gregorian::date third_thursday() const { return find_nth_weekday(3, Thursday); }
    boost::gregorian::date third_friday() const { return find_nth_weekday(3, Friday); }
    boost::gregorian::date third_saturday() const { return find_nth_weekday(3, Saturday); }
    boost::gregorian::date third_sunday() const { return find_nth_weekday(3, Sunday); }

    boost::gregorian::date fourth_monday() const { return find_nth_weekday(4, Monday); }
    boost::gregorian::date fourth_tuesday() const { return find_nth_weekday(4, Tuesday); }
    boost::gregorian::date fourth_wednesday() const { return find_nth_weekday(4, Wednesday); }
    boost::gregorian::date fourth_thursday() const { return find_nth_weekday(4, Thursday); }
    boost::gregorian::date fourth_friday() const { return find_nth_weekday(4, Friday); }
    boost::gregorian::date fourth_saturday() const { return find_nth_weekday(4, Saturday); }
    boost::gregorian::date fourth_sunday() const { return find_nth_weekday(4, Sunday); }

    boost::gregorian::date last_monday() const { return find_last_weekday(Monday); }
    boost::gregorian::date last_tuesday() const { return find_last_weekday(Tuesday); }
    boost::gregorian::date last_wednesday() const { return find_last_weekday(Wednesday); }
    boost::gregorian::date last_thursday() const { return find_last_weekday(Thursday); }
    boost::gregorian::date last_friday() const { return find_last_weekday(Friday); }
    boost::gregorian::date last_saturday() const { return find_last_weekday(Saturday); }
    boost::gregorian::date last_sunday() const { return find_last_weekday(Sunday); }

private:
    int month;
    int year;

    boost::gregorian::date find_nth_weekday(int n, Weekday weekday) const {
        boost::gregorian::date first_day_of_month(year, month, 1);
        boost::gregorian::greg_weekday first_weekday = first_day_of_month.day_of_week();
        int days_to_add = (weekday - first_weekday + 8) % 7;
        boost::gregorian::date first_occurrence = first_day_of_month + boost::gregorian::days(days_to_add);

        return first_occurrence + boost::gregorian::days(7 * (n - 1));
    }

    boost::gregorian::date find_teenth(Weekday weekday) const {
        boost::gregorian::date first_day_of_month(year, month, 13);
        boost::gregorian::greg_weekday first_teenth_weekday = first_day_of_month.day_of_week();

        int days_to_add = (weekday - first_teenth_weekday + 8) % 7;
        boost::gregorian::date first_teenth = first_day_of_month + boost::gregorian::days(days_to_add);

        return first_teenth;
    }

    boost::gregorian::date find_last_weekday(Weekday weekday) const {
        int next_month = month == 12 ? 1 : month + 1;
        int next_year = month == 12 ? year + 1 : year;
        boost::gregorian::date first_day_of_next_month(next_year, next_month, 1);
        boost::gregorian::date last_day_of_month = first_day_of_next_month - boost::gregorian::days(1);

        int days_to_subtract = (last_day_of_month.day_of_week() - weekday + 6) % 7;
        boost::gregorian::date last_occurrence = last_day_of_month - boost::gregorian::days(days_to_subtract);

        return last_occurrence;
    }
};

}  // namespace meetup

#endif // MEETUP_H
