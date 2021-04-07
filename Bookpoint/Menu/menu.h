#ifndef BOOKPOINT_MENU_H
#define BOOKPOINT_MENU_H

/// Main menu
void activateMenu();

/// Submenus
void dateOperations();

void personOperations();

void publisherOperations();

void bookOperations();

// Helper functions for book operations
void bookOperations_authorID();
void bookOperations_pageNumber();
void bookOperations_priceRange();
void bookOperations_publishDate();
void bookOperations_cover();

#endif //BOOKPOINT_MENU_H
