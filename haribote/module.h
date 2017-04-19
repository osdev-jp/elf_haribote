#ifndef MODULE_H_
#define MODULE_H_

struct module {
    int (*init)(void);
    void (*exit)(void);
};

#endif // MODULE_H_
