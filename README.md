# colorOverlay
Application to add a color overlay and overwrite the origin file

![](https://github.com/thebino/colorOverlay/workflows/Build%20&%20Deploy%20releases/badge.svg)


## Installation

To build the project, download [cmake](https://cmake.org/download/) and [qt5](https://qt.io/download)

You also have to set the `Qt5_DIR` or `CMAKE_PREFIX_PATH` to your Qt5 library directory.

```sh
cmake . -B build
```

Optional: Set the path directly
```sh
Qt5_DIR="/path/to/Qt5/5.14.1/lib/cmake/Qt5/" cmake . -B build
```

```sh
cmake --build build
```


## Release History

* 0.0.1
    * First draft


## Meta

Benjamin Stürmer – [@benjaminstrmer](https://twitter.com/benjaminstrmer) – webmaster@stuermer-benjamin.de

Distributed under the GNU General Public License 3 (CC BY 4.0) license. See [``LICENSE``](LICENSE) for more information.


## Thanks

* [Michele Caini](https://github.com/skypjack) his [shared notes](https://skypjack.github.io/2019-10-23-gh-greets-qt/) on building qt projects with github actions helped me workaround similar issues on public github actions

* [Vincent Lee](https://github.com/euler0) his [mini-cmake-qt](https://github.com/euler0/mini-cmake-qt) template helped me on packaging for macOS and Windows.


## Contributing

1. Fork it (https://github.com/thebino/colorOverlay/fork)
2. Create a feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request
