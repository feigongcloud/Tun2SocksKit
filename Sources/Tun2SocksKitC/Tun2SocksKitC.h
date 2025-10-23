#ifndef Tun2SocksKitC_H
#define Tun2SocksKitC_H

#include <stdint.h>

#define CTLIOCGINFO 0xc0644e03UL

struct ctl_info {
    uint32_t   ctl_id;
    char        ctl_name[96];
};
struct sockaddr_ctl {
    unsigned char      sc_len;
    unsigned char      sc_family;
    uint16_t   ss_sysaddr;
    uint32_t   sc_id;
    uint32_t   sc_unit;
    uint32_t   sc_reserved[5];
};

#endif /* Tun2SocksKitC_H */

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*OnNewConnectionCallback)(const char *ip, int port);

/* Swift 调用此函数注册回调 */
void Tun2SocksKitC_SetOnNewConnection(OnNewConnectionCallback cb);

/* 转发到底层 HevSocks5Tunnel */
int32_t hev_socks5_tunnel_main(const char *config_path, int32_t tun_fd);
int32_t hev_socks5_tunnel_main_from_str(const char *config_str, uint32_t len, int32_t tun_fd);
void hev_socks5_tunnel_stats(int *tx_packets, int *tx_bytes, int *rx_packets, int *rx_bytes);
void hev_socks5_tunnel_quit(void);
void hev_socks5_tunnel_set_on_new_connection(OnNewConnectionCallback cb);

#ifdef __cplusplus
}
#endif
