import argparse
from functools import wraps
import glob
import os
import os.path
from os.path import join
import os.path
import shutil
import subprocess

sphinx_opts    = '-q -N'
sphinx_build   = 'sphinx-build'
source_dir     = 'source'
build_dir      = 'build'
doxygen_dir    = 'doxygen'
doxygen_xml    = join(doxygen_dir,'xml','index.xml')

indent = 0

def action(func):
    @wraps(func)
    def wrapped(*args, **kwargs):
        global indent
        log('%s:' % (wrapped.__name__))
        indent += 2
        x = func(*args, **kwargs)
        indent -= 2
        return x
    return wrapped

class cd:
    """Context manager for changing the current working directory"""
    def __init__(self, newPath):
        self.newPath = os.path.expanduser(newPath)

    def __enter__(self):
        self.savedPath = os.getcwd()
        log('cd ' + self.newPath)
        os.chdir(self.newPath)

    def __exit__(self, etype, value, traceback):
        os.chdir(self.savedPath)

def log(*args, **kwargs):
    print(indent * ' ' + ' '.join(map(str,args)), flush = True, **kwargs)
    
def shell(c):
    log(c)
    if args.dry_run:
        return
    subprocess.check_call(c, shell=True)

def rm(dir):
    log('rm -rf', dir)
    if args.dry_run:
        return
    shutil.rmtree(dir, ignore_errors=True)
    
def copytree(src, dst):
    log('cp -r', src, dst)
    if args.dry_run:
        return
    shutil.copytree(src, dst)
    
def copy(src, dst):
    log('cp', src, dst)
    if args.dry_run:
        return
    shutil.copy(src, dst)
    
def makedirs(path):
    log('mkdir -p', path)
    if args.dry_run:
        return
    os.makedirs(path)

def sphinx(target):
    os.environ['LATEXMKOPTS'] = '--silent'
    os.environ['LATEXOPTS'] = '-interaction=nonstopmode -halt-on-error'
    opts = sphinx_opts + (' -W' if args.W else '')
    shell('%s -M %s %s %s %s' % (sphinx_build,
                                 target,
                                 source_dir,
                                 build_dir,
                                 opts))

def up_to_date(target, deps):
    if not os.path.exists(target):
        print('exists')
        return False
    for dep in deps:
        if os.path.getmtime(target) < os.path.getmtime(dep):
            print('time')
            return False
    return True

def doxygen_files():
    return ['Doxyfile'] + glob.glob(join('include','**'), recursive=True)

def doxygen(target=None):
    doxyfile = 'Doxyfile'
    if (not os.path.exists(doxyfile) or
        up_to_date(doxygen_xml, doxygen_files())):
        return
    shell('doxygen %s' % doxyfile)

@action
def prep(target=None):
    doxygen()

@action
def build(target):
    prep()
    sphinx(target)

@action
def clean(target=None):
    rm('doxygen')
    sphinx('clean')

commands = {'clean': clean,
            'html': build,
            'latexpdf': build,
            'spelling': build,
            'prep': prep}

def main():
    global args
    parser = argparse.ArgumentParser(description='Build doc.')
    parser.add_argument('action',choices=commands.keys())
    parser.add_argument('--dry-run', action='store_true')
    parser.add_argument('-W', action='store_true')
    args = parser.parse_args()

    commands[args.action](args.action)

main()
