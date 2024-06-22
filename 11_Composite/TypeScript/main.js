"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.MyDirectory = exports.MyFile = void 0;
var MyFile = /** @class */ (function () {
    function MyFile(_name) {
        this._name = _name;
    }
    MyFile.prototype.remove = function () {
        console.log(this._name + " Deleted!");
    };
    return MyFile;
}());
exports.MyFile = MyFile;
var MyDirectory = /** @class */ (function () {
    function MyDirectory(_name) {
        this._name = _name;
        this._list = [];
    }
    MyDirectory.prototype.add = function (entry) {
        this._list.push(entry);
    };
    MyDirectory.prototype.remove = function () {
        this._list.forEach(function (item) { return item.remove(); });
        console.log(this._name + " Deleted!");
    };
    return MyDirectory;
}());
exports.MyDirectory = MyDirectory;
var file1 = new MyFile("file1");
var file2 = new MyFile("file2");
var file3 = new MyFile("file3");
var file4 = new MyFile("file4");
var dir1 = new MyDirectory("dir1");
dir1.add(file1);
var dir2 = new MyDirectory("dir2");
dir2.add(file2);
dir2.add(file3);
dir1.add(dir2);
dir1.add(file4);
dir1.remove();
