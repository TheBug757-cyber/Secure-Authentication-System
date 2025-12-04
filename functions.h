#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void register_user();
void login_user();
int encrypt_password(const char* password, char* encrypted_password);

int validate_password(const char* password);

#endif
