// empty
#include "Tun2SocksKitC.h"
#include <HevSocks5Tunnel/hev-socks5-tunnel.h>

void Tun2SocksKitC_SetOnNewConnection(OnNewConnectionCallback cb) {
    hev_socks5_tunnel_set_on_new_connection(cb);
}
