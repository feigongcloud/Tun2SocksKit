#ifndef Tun2SocksKitC_H
#define Tun2SocksKitC_H


#include <sys/types.h>

#define CTLIOCGINFO 0xc0644e03UL

struct ctl_info {
    u_int32_t   ctl_id;       // 使用 u_int32_t 而不是 uint32_t
    char        ctl_name[96];
};

struct sockaddr_ctl {
    u_char      sc_len;       // 使用 u_char 与系统一致
    u_char      sc_family;
    uint16_t    ss_sysaddr;
    u_int32_t   sc_id;        // 同样使用 u_int32_t
    u_int32_t   sc_unit;
    u_int32_t   sc_reserved[5];
};

#endif /* Tun2SocksKitC_H */
