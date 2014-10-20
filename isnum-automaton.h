class Solution {
public:
    int next(int status, char input) {
        switch (status) {
            case 0:
                if (input == '0') return 4;
                if (isdigit(input)) return 1;
                if (input == '.') return 9;
                break;
            case 1:
                if (input == '.') return 3;
                if (isdigit(input)) return 1;
                if (input == '\0') return 99;
                if (input == 'e') return 7;
                break;
            case 2:
                if (isdigit(input)) return 3;
                if (input == '\0') return 99;
                break;
            case 3:
                if (input == '\0') return 99;
                if (isdigit(input)) return 3;
                if (input == 'e') return 7;
                break;
            case 4:
                if (input == 'x') return 5;
                if (isdigit(input)) return 1;
                if (input == '\0') return 99;
                if (input == '.') return 2;
                if (input == 'e') return 7;
                break;
            case 5:
                if (isdigit(input) || (input >= 'a' && input <= 'f') || (input >= 'A' && input <= 'F')) return 6;
                break;
            case 6:
                if (isdigit(input) || (input >= 'a' && input <= 'f') || (input >= 'A' && input <= 'F')) return 6;
                if (input == '\0') return 99;
                break;
            case 7:
                if (isdigit(input)) return 8;
                if (input == '+' || input == '-') return 10;
                break;
            case 8:
                if (isdigit(input)) return 8;
                if (input == '\0') return 99;
                break;
            case 9:
                if(isdigit(input)) return 3;
                break;
            case 10:
                if (isdigit(input)) return 8;
                break;
            default:
                break;
        }
        return -1;
    }

    bool isNumber(const char *s) {
        int len = strlen(s);

        int start = 0;
        while (start < len && s[start] == ' ') start++;
        if (start >= len) return false;

        if (s[start] == '-' || s[start] == '+') start++;
        if (start >= len) return false;

        int end = len - 1;
        while (end >= start && s[end] == ' ') end--;

        int status = 0;
        for (int i = start; i <= end; i++) {
            status = next(status, s[i]);
            if (status < 0) return false;
        }
        status = next(status, '\0');
        return (status == 99);
    }
};
