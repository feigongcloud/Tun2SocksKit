// swift-tools-version: 5.7

import PackageDescription

let package = Package(
  name: "Tun2SocksKit",
  platforms: [.iOS(.v12), .macOS(.v12)],
  products: [
    .library(
        name: "Tun2SocksKit",
        targets: ["Tun2SocksKit"]
    ),
    .library(
        name: "Tun2SocksKitC",
        targets: ["Tun2SocksKitC"]
    )
  ],
  targets: [
    .target(
        name: "Tun2SocksKit",
        dependencies: ["HevSocks5Tunnel", "Tun2SocksKitC"]
    ),
    .target(
        name: "Tun2SocksKitC",
        publicHeadersPath: "."
    ),
    .binaryTarget(
        name: "HevSocks5Tunnel",
        url: "https://github.com/feigongcloud/Tun2SocksKit/releases/download/tun2socksSjyV01/HevSocks5Tunnel.xcframework.zip",
        checksum: "0d515615b04dfec9ce503e6a83601605b41bf2661b345822f6da15a19006e5b9"
    )
  ]
)
