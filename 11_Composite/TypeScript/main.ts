import { IDirectoryEntory } from "./type"

export class MyFile implements IDirectoryEntory {
    constructor(
        private _name: string
    ) { }

    public remove() {
        console.log(this._name + " Deleted!")
    }
}

export class MyDirectory implements IDirectoryEntory {
    private _list: Array<IDirectoryEntory>
    constructor(
        private _name: string,
    ) {
        this._list = []
    }

    public add(entry: IDirectoryEntory) {
        this._list.push(entry)
    }

    public remove() {
        this._list.forEach((item) => item.remove())
        console.log(this._name + " Deleted!")
    }
}
const file1 = new MyFile("file1")
const file2 = new MyFile("file2")
const file3 = new MyFile("file3")
const file4 = new MyFile("file4")

const dir1 = new MyDirectory("dir1")
dir1.add(file1)

const dir2 = new MyDirectory("dir2")
dir2.add(file2)
dir2.add(file3)
dir1.add(dir2)
dir1.add(file4)

dir1.remove()


