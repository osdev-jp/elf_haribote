## ファイル構成

次のようなファイル配置にする。

    tolset_h/
        elf_haribote/
           haribote.rul
           ...
    tolset_p86/
        z_tools/
            i386-elf-gcc/
                ...

tolset_h は[「30日でできる！ OS自作入門」のサポートページ](http://hrb.osask.jp/) よりダウンロード可能。

tolset_p86 は [『自作エミュレータで学ぶx86アーキテクチャ』サポートページ](https://book.mynavi.jp/support/bookmook/x86/) よりダウンロード可能。

## ビルド・実行

`tolset_h/elf_haribote/!cons_nt.bat` を開いて次のコマンドを実行。

    make full
    make run
