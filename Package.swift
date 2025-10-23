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
          dependencies: ["HevSocks5Tunnel"],
          path: "Sources/Tun2SocksKitC",
          publicHeadersPath: ".",
          cSettings: [
              .headerSearchPath(".")
          ]
    ),
    .binaryTarget(
        name: "HevSocks5Tunnel",
        url: "https://github.com/feigongcloud/Tun2SocksKit/releases/download/tunsocks5-0x89-vp/HevSocks5Tunnel.xcframework.zip",
        checksum: "4c8bfcdb6d5b603abc584765bb521efc86ff4a56fcb2f42682f59375aa15056e"
    )
  ]
)
