# Automated Skia builds

This repo is dedicated to building Skia binaries for use in [Skiko](https://github.com/JetBrains/skiko).

## Prebuilt binaries

- JetBrains build is MT mode
- This repo build is MD mode

Prebuilt binaries can be found [in releases](https://github.com/programClown/skia-pack/releases).

## Building next version of Skia

Update `version` in [.github/workflows/build.yml](https://github.com/programClown/skia-pack/blob/master/.github/workflows/build.yml).

## Building locally

```sh
python3 script/checkout.py --version m105-f204b137b9-5
python3 script/build.py
python3 script/archive.py
```

To build a debug build:

```sh
python3 script/checkout.py --version m105-f204b137b9-5
python3 script/build.py --build-type Debug
python3 script/archive.py --build-type Debug
```

# skiaMdPro

VS2019/VS2022 project test