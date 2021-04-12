#ifndef BOOKPOINT_MENU_H
#define BOOKPOINT_MENU_H

/// Main menu
void activateMenu();

/// Submenus
void dateOperations();
void personOperations();
void publisherOperations();
void bookOperations();

/// Helper functions for book operations
void bookOperations_authorID();
void bookOperations_pageNumber();
void bookOperations_priceRange();
void bookOperations_publishDate();
void bookOperations_cover();

/// Helper functions for publisher operations
void publisherOperations_getPublisherByName();
void publisherOperations_getPublisherByAddress();
void publisherOperations_checkExistenceByAddress();
void publisherOperations_publisherCountBetweenDates();

/// Helper functions for person operations
void personOperations_getPersonByID();
void personOperations_printPeopleByNationality();
void personOperations_printPeopleByBirthDate();

#endif //BOOKPOINT_MENU_H