#ifndef GAME_SETTING_H
#define GAME_SETTING_H



class game_setting {
    public:
    int windows_size_width;
    int windows_size_height;

    int get_windows_size_width() const;
    void set_windows_size_width(int width);

    int get_windows_size_height() const;
    void set_windows_size_height(int height);
};



#endif //GAME_SETTING_H
