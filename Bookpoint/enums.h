#ifndef BOOKPOINT_ENUMS_H
#define BOOKPOINT_ENUMS_H

/// This enum lists the cover types
enum Cover {
    // Source: https://www.blurb.com/blog/3-types-of-book-covers/
    SOFTCOVER = 0,
    HARDCOVER_IMAGEWRAP = 1,
    HARDCOVER_DUSTJACKET = 2
};

/// This enum lists the nationalities (not all of them)
enum Nationality {
    HUNGARIAN = 0,
    ROMANIAN = 1,
    GERMAN = 2,
    FRENCH = 3,
    AMERICAN = 4,
    BRITISH = 5,
    DANISH = 6,
    ICELANDIC = 7,
    IRISH = 8,
    SWEDISH = 9
};

#endif //BOOKPOINT_ENUMS_H
