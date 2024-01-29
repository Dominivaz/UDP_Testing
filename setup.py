from setuptools import setup

setup_args = {
    'name': 'UDP_Test', 
    'author': 'Dominic',
    'url': 'https://github.com/Dominivaz/UDP_Testing.git',
    'license': 'bsd',
    'description': 'UDP Test',
    'version': '1.0.1',
    'install_requires': ['numpy>=1.14'],
    'package_dir': {'UDP_Test':'UDP_Test'},
    'packages': ['UDP_Test'],
}

if __name__ == '__main__':
    setup(**setup_args)