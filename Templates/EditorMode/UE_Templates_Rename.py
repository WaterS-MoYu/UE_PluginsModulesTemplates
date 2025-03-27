import os

replacements = {
    "MY_PLUGIN_NAME": "EXAMPLE_Plugin",
    "MY_MODULE_NAME": "EXAMPLE_Module",
    "MY_MODULE_CLASS": "EXAMPLE_Class"
}
folder_path = os.path.dirname(os.path.abspath(__file__))

def rename_files_and_folders(root_dir):
    for dirpath, dirnames, filenames in os.walk(root_dir, topdown=False):
        for filename in filenames:
            new_name = filename
            for old, new in replacements.items():
                if old in new_name:
                    new_name = new_name.replace(old, new)
            if filename != new_name:
                old_path = os.path.join(dirpath, filename)
                new_path = os.path.join(dirpath, new_name)
                os.rename(old_path, new_path)
                print(f"重命名文件: {old_path} -> {new_path}")
        for dirname in dirnames:
            new_name = dirname
            for old, new in replacements.items():
                if old in new_name:
                    new_name = new_name.replace(old, new)
            if dirname != new_name:
                old_path = os.path.join(dirpath, dirname)
                new_path = os.path.join(dirpath, new_name)
                os.rename(old_path, new_path)
                print(f"重命名文件夹: {old_path} -> {new_path}")

if __name__ == "__main__":
    print("当前脚本所在的目录:", folder_path)
    if os.path.exists(folder_path):
        rename_files_and_folders(folder_path)
        print("处理完成！")
    else:
        print("路径不存在，请检查输入！")
