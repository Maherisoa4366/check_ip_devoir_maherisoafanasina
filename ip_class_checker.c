#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void determine_ip_class(char *ip_address) { 
    int first_octet;
    char *query_string;

    query_string = getenv("QUERY_STRING");
    sscanf(query_string, "ip=%99[^&]", ip_address);
    sscanf(query_string, "ip=%d", &first_octet);
    
    printf("Content-Type: text/html\n\n");
    printf("<!DOCTYPE html>\n<html>\n<head>\n<title>IP Address Classification</title>\n</head>\n<body>\n");

    if (first_octet >= 0 && first_octet <= 127) {
        printf("<h3>The IP belongs to Class A</h3>\n");
    } else if (first_octet >= 128 && first_octet <= 191) {
        printf("<h3>The IP belongs to Class B</h3>\n");
    } else if (first_octet >= 192 && first_octet <= 223) {
        printf("<h3>The IP belongs to Class C</h3>\n");
    } else if (first_octet >= 224 && first_octet <= 239) {
        printf("<h3>The IP belongs to Class D</h3>\n");
    } else if (first_octet >= 240 && first_octet <= 255) {
        printf("<h3>The IP belongs to Class E</h3>\n");
    } else {
        printf("<h3>Invalid IP Address</h3>\n");
    }

    printf("<br><a href=\"index.html\">Check Another IP</a>\n");
    printf("</body>\n</html>\n");
}

int main() {
    char ip_address[16];
    
    fgets(ip_address, sizeof(ip_address), stdin);
    ip_address[strcspn(ip_address, "\n")] = '\0';
    
    determine_ip_class(ip_address);

    return 0;
}