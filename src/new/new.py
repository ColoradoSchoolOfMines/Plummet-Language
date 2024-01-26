import os
import sys
import json
import enum


class ProjectInformaton:
    def __init__(self, name: str, version: str, description: str, entrypoint: str):
        self.name: str = name
        self.version: str = version
        self.description: str = description
        self.entrypoint: str = entrypoint


    def to_json(self):
        return {
            self.name: {
                "version": self.version,
                "description": self.description,
                "entrypoint": self.entrypoint
            }
        }


class ProjectType(enum.Enum):
    program = "prog"
    library = "lib"


def help_command() -> None:
    print("Usage: Subcommand: new [help/library/program]")


def valid_version(version: str) -> bool:
    version: list[str] = version.split(".")
    
    if len(version) != 3:
        return False
    
    for v in version:
        if not v.isdigit():
            return False
    
    return True


def get_information(project_type: ProjectType) -> ProjectInformaton:
    name: str = None
    while not name:
        name = input("Project name: ")
        name = name.strip()

        if not name:
            print("Project name cannot be empty")

    name = "_".join(name.lower().split(" ")) + "_" + project_type.value

    version: str = None
    while not version:
        version = input("Project version: ")
        version = version.strip()

        if not version:
            print("Project version cannot be empty")

        if not valid_version(version):
            print("Invalid version format")
            version = None

    description: str = None
    while not description:
        description = input("Project description: ")
        description = description.strip()

        if not description:
            print("Project description cannot be empty")

    # NOTE: for now this will be defaulted to ./main.plmt
    entrypoint: str = "./main.plmt"

    return ProjectInformaton(name, version, description, entrypoint)


def make_project(project_type: ProjectType) -> None:
    project_info: ProjectInformaton = get_information(project_type)

    print("Creating project...")

    if os.path.exists(project_info.name):
        print(f"Project {project_info.name} already exists")
        sys.exit(1)

    os.mkdir(project_info.name)

    open(f"{project_info.name}/main.plmt", "w").write(
        "TODO: Implement this once the syntax is finalized"
    )

    open(f"{project_info.name}/README.md", "w").write(
        f"# {project_info.name}\n\n{project_info.description}"
    )

    open(f"{project_info.name}/config.json", "w").write(
        json.dumps(project_info.to_json(), indent = 4)
    )


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Invalid number of arguments: {len(sys.argv)}")
        help_command()
        sys.exit(4)

    if sys.argv[1] == "help":
        help_command()
        sys.exit(0)

    if sys.argv[1] == "program":
        make_project(ProjectType.program)
        sys.exit(0)

    if sys.argv[1] == "library":
        make_project(ProjectType.library)
        sys.exit(0)

    print(f"Invalid subcommand: {sys.argv[1]}")
    help_command()
    sys.exit(4)