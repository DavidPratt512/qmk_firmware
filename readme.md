# QMK Fork

This is my fork of [qmk_firmware](https://github.com/qmk/qmk_firmware).

## Keyboards

Other keyboard configs are kept on other branches (in parentheses):

* gmmk/pro/rev1/ansi (gmmk)
* kbdfans/niu_mini (niu_mini)
* **keebio/iris** (iris)
* pauperboards/brick (brick)
* planck (planck)

I'm using different branches to effectively pin the version of qmk each board
is built with.

## Planck

This is the branch for my **planck** configuration. The keymap is in the
`keyboards/planck/keymaps/davidpratt512` directory.

Make the firmware with

```sh
make planck/rev6:davidpratt512[:flash]
```
